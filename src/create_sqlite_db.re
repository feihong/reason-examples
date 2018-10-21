open Sqlite;

let db = makeDatabase("test.db", ~memory=true, ());

let result =
  db->Database.prepare("select ? + ? as value")->Statement.get([|11, 4|]);
Js.log(result##value);
