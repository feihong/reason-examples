[%bs.raw {|require('isomorphic-fetch')|}];

module Response = {
  [@bs.send]
  external buffer: Fetch.Response.t => Js.Promise.t(Node.Buffer.t) = "";
};

module Fs = {
  [@bs.val] [@bs.module "fs"]
  external writeBufferToFileSync: (string, Node.Buffer.t) => unit =
    "writeFileSync";
};

module Buffer = {
  [@bs.get] external length: Node.Buffer.t => int = "";
};

let () =
  Js.Promise.(
    Fetch.fetch("https://picsum.photos/100/100/?random")
    |> then_(Response.buffer)
    |> then_(buffer => {
         Js.log("Size in bytes: " ++ buffer->Buffer.length->string_of_int);
         Fs.writeBufferToFileSync("random.jpg", buffer);
         Js.log("Wrote file to random.jpg");
         resolve();
       })
  )
  ->ignore;
