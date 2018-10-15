module Fs = {
  include Node.Fs;

  [@bs.val] [@bs.module "fs"]
  external writeBufferToFileSync: (string, Node.Buffer.t) => unit =
    "writeFileSync";

  [@bs.val] [@bs.module "fs"]
  external readBufferFromFileSync: string => Node.Buffer.t = "readFileSync";
};

module Buffer = {
  include Node.Buffer;
  [@bs.get] external length: Node.Buffer.t => int = "";
};

module Zlib = {
  [@bs.val] [@bs.module "zlib"]
  external gzipSync: Node.Buffer.t => Node.Buffer.t = "";

  [@bs.val] [@bs.module "zlib"]
  external gunzipSync: Node.Buffer.t => Node.Buffer.t = "";
};
