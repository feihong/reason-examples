open Interop;

let url = "https://www.mdbg.net/chinese/export/cedict/cedict_1_0_ts_utf-8_mdbg.txt.gz";
let filename = "cedict.txt.gz";

type entry = {
  simp: string,
  trad: string,
  pinyin: string,
  gloss: string,
};

if (Fs.existsSync(filename)) {
  Js.log("Reading " ++ filename);
  let readStream = Fs.createReadStream(filename);
  let gunzip = Zlib.createGunzip();
  Stream.pipeline([|readStream, gunzip|]);
  let interface = Readline.createInterface(~input=gunzip, ());

  let re = [%bs.re {|/(.*) (.*) \[(.*)\] \/(.*)\//|}];

  interface->Readline.onLine(line =>
    Js.Re.exec(line, re)
    ->Option.map(result => {
        let arr =
          result
          ->Js.Re.captures
          ->Array.map(x =>
              x->Js.Nullable.toOption->Option.getWithDefault("")
            );
        let entry = {
          simp: arr->Array.getExn(1),
          trad: arr->Array.getExn(2),
          pinyin: arr->Array.getExn(3),
          gloss: arr->Array.getExn(4),
        };
        Js.log2(entry.simp, entry.gloss);
      })
    ->ignore
  );

  interface->Readline.onClose(_ => Js.log("No more lines"));
} else {
  Js.Promise.(
    Axios.getc(url, Axios.makeConfig(~responseType="arraybuffer", ()))
    |> then_(res => {
         let buffer: Buffer.t = res##data;
         Fs.writeBufferToFileSync(filename, buffer);
         resolve();
       })
  )
  ->ignore;
};
