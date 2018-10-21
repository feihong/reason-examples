module Statement = {
  type t;

  [@bs.send] [@bs.splice] external get: (t, array('a)) => Js.t({..}) = "";

  [@bs.send] external getNamed: (t, Js.t({..})) => Js.t({..}) = "get";

  [@bs.send] [@bs.splice] external run: (t, array('a)) => Js.Json.t = "";
};

module Database = {
  type t;

  [@bs.deriving abstract]
  type options = {
    [@bs.optional]
    memory: bool,
    [@bs.optional]
    readonly: bool,
    [@bs.optional]
    fileMustExist: bool,
    [@bs.optional]
    timeout: int,
  };

  [@bs.new] [@bs.module]
  external makeDatabase: (string, options) => t = "better-sqlite3";

  [@bs.send] external prepare: (t, string) => Statement.t = "";
};

let makeDatabase =
    (path, ~memory=?, ~readonly=?, ~fileMustExist=?, ~timeout=?, ()) =>
  Database.makeDatabase(
    path,
    Database.options(~memory?, ~readonly?, ~fileMustExist?, ~timeout?, ()),
  );
