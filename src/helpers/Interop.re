module Buffer = {
  include Node.Buffer;

  [@bs.get] external length: t => int = "";
};

module Stream = {
  type t;

  [@bs.module "stream"] [@bs.splice] external pipeline: array(t) => unit = "";
};

module Fs = {
  include Node.Fs;

  [@bs.module "fs"]
  external writeBufferToFileSync: (string, Buffer.t) => unit = "writeFileSync";

  [@bs.module "fs"]
  external readBufferFromFileSync: string => Buffer.t = "readFileSync";

  [@bs.module "fs"] external createReadStream: string => Stream.t = "";
};

module Zlib = {
  [@bs.module "zlib"] external gzipSync: Buffer.t => Buffer.t = "";

  [@bs.module "zlib"] external gunzipSync: Buffer.t => Buffer.t = "";

  [@bs.module "zlib"] external createGunzip: unit => Stream.t = "";
};

module Readline = {
  type interface;

  [@bs.deriving abstract]
  type options = {
    input: Stream.t,
    [@bs.optional]
    output: Stream.t,
  };

  [@bs.module "readline"]
  external createInterface_: options => interface = "createInterface";

  let createInterface = (~input: Stream.t, ~output: option(Stream.t)=?, ()) =>
    createInterface_(options(~input, ~output?, ()));

  [@bs.send]
  external onLine: (interface, [@bs.as "line"] _, string => unit) => unit =
    "on";

  [@bs.send]
  external onClose: (interface, [@bs.as "close"] _, unit => unit) => unit =
    "on";
};
