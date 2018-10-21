// Generated by BUCKLESCRIPT VERSION 4.0.6, PLEASE EDIT WITH CARE
'use strict';

var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var BetterSqlite3 = require("better-sqlite3");

var Statement = /* module */[];

var Database = /* module */[];

function makeDatabase(path, memory, readonly, fileMustExist, timeout, _) {
  var tmp = { };
  if (memory !== undefined) {
    tmp.memory = Js_primitive.valFromOption(memory);
  }
  if (readonly !== undefined) {
    tmp.readonly = Js_primitive.valFromOption(readonly);
  }
  if (fileMustExist !== undefined) {
    tmp.fileMustExist = Js_primitive.valFromOption(fileMustExist);
  }
  if (timeout !== undefined) {
    tmp.timeout = Js_primitive.valFromOption(timeout);
  }
  return new BetterSqlite3(path, tmp);
}

exports.Statement = Statement;
exports.Database = Database;
exports.makeDatabase = makeDatabase;
/* better-sqlite3 Not a pure module */