type readStream;
type readable;

module Fs = {
  include Node.Fs;

  [@bs.module "fs"]
  external writeBufferToFileSync: (string, Node.Buffer.t) => unit =
    "writeFileSync";

  [@bs.module "fs"]
  external readBufferFromFileSync: string => Node.Buffer.t = "readFileSync";

  [@bs.module "fs"] external createReadStream: string => readStream = "";
};

module Readline = {
  type interface;
  type readable;

  external readStreamToReadable: readStream => readable = "%identity";

  type options = Js.t({.});

  [@bs.obj] external makeOptions: (~input: readable) => options = "";
  [@bs.module "readline"] external createInterface: options => interface = "";
};

module Buffer = {
  include Node.Buffer;

  [@bs.get] external length: Node.Buffer.t => int = "";
};

module Zlib = {
  [@bs.module "zlib"] external gzipSync: Node.Buffer.t => Node.Buffer.t = "";

  [@bs.module "zlib"] external gunzipSync: Node.Buffer.t => Node.Buffer.t = "";
};
