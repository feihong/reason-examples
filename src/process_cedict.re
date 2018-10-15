open Util;

let url = "https://www.mdbg.net/chinese/export/cedict/cedict_1_0_ts_utf-8_mdbg.txt.gz";
let filename = "cedict.txt.gz";

if (Fs.existsSync(filename)) {
  Js.log("Reading " ++ filename);
  let str =
    Fs.readBufferFromFileSync(filename)->Zlib.gunzipSync->Buffer.toString;
  Js.log(str);
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
  Js.log("Downloaded " ++ filename);
};
