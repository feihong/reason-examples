/**
 * https://github.com/JoshuaWise/better-sqlite3/blob/master/docs/api.md
 */
module Statement = {
  type t;

  [@bs.send] external get: (t, unit) => 'a = "";

  [@bs.send] external getWithArgs: (t, 'a) => 'b = "get";

  [@bs.send] external all: (t, unit) => 'a = "";

  [@bs.send] external run: (t, unit) => 'a = "";

  [@bs.send] external runWithArgs: (t, 'a) => 'b = "run";
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

  [@bs.send] external transaction: (t, 'a => unit, 'a) => unit = "";

  [@bs.send] external exec: (t, string) => t = "";

  [@bs.send] external close: (t, unit) => t = "";
};

let makeDatabase =
    (path, ~memory=?, ~readonly=?, ~fileMustExist=?, ~timeout=?, ()) =>
  Database.makeDatabase(
    path,
    Database.options(~memory?, ~readonly?, ~fileMustExist?, ~timeout?, ()),
  );
