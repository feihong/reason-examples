let cfg = Axios.makeConfig(~responseType="arraybuffer", ());

let () =
  Js.Promise.(
    Axios.getc("https://picsum.photos/100/100/?random", cfg)
    |> then_(res => {
         open Interop;
         let buffer: Node.Buffer.t = res##data;
         Js.log("Size in bytes: " ++ buffer->Buffer.length->string_of_int);
         Fs.writeBufferToFileSync("random.jpg", buffer);
         Js.log("Wrote file to random.jpg");
         resolve();
       })
  )
  ->ignore;
