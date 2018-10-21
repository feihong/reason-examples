type stream;

module Buffer = {
  include Node.Buffer;

  [@bs.get] external length: t => int = "";
};

module Fs = {
  include Node.Fs;

  [@bs.module "fs"]
  external writeBufferToFileSync: (string, Buffer.t) => unit = "writeFileSync";

  [@bs.module "fs"]
  external readBufferFromFileSync: string => Buffer.t = "readFileSync";

  [@bs.module "fs"] external createReadStream: string => stream = "";
};

module Stream = {
  [@bs.module "stream"] external pipeline: (stream, stream) => unit = "";
};

module Zlib = {
  [@bs.module "zlib"] external gzipSync: Buffer.t => Buffer.t = "";

  [@bs.module "zlib"] external gunzipSync: Buffer.t => Buffer.t = "";

  [@bs.module "zlib"] external createGunzip: unit => stream = "";
};

module Readline = {
  type interface;

  [@bs.deriving abstract]
  type options = {
    input: stream,
    [@bs.optional]
    output: stream,
  };

  [@bs.module "readline"]
  external createInterface_: options => interface = "createInterface";

  let createInterface = (~input: stream, ~output: option(stream)=?, ()) =>
    createInterface_(options(~input, ~output?, ()));

  [@bs.send]
  external onLine: (interface, [@bs.as "line"] _, string => unit) => unit =
    "on";

  [@bs.send]
  external onClose: (interface, [@bs.as "close"] _, unit => unit) => unit =
    "on";
};
