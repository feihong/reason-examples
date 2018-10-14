module Fs = {
  [@bs.val] [@bs.module "fs"]
  external writeBufferToFileSync: (string, Node.Buffer.t) => unit =
    "writeFileSync";
};

module Buffer = {
  [@bs.get] external length: Node.Buffer.t => int = "";
};
