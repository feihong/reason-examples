[%bs.raw {|require('isomorphic-fetch')|}];

module Response = {
  [@bs.send]
  external buffer: Fetch.Response.t => Js.Promise.t(Node.Buffer.t) = "";
};

let () =
  Js.Promise.(
    Fetch.fetch("https://picsum.photos/100/100/?random")
    |> then_(Response.buffer)
    |> then_(buffer => {
         open Interop;
         Js.log("Size in bytes: " ++ buffer->Buffer.length->string_of_int);
         Fs.writeBufferToFileSync("random.jpg", buffer);
         Js.log("Wrote file to random.jpg");
         resolve();
       })
  )
  ->ignore;
