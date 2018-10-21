open Sqlite;

let db = makeDatabase("test.db", ~memory=true, ());

let result =
  db->Database.prepare("select ? + ? as value")->Statement.get([|11, 4|]);
Js.log(result##value);

let result2 =
  db
  ->Database.prepare("select $a + $b as value")
  ->Statement.getNamed({"a": 44, "b": 22});
Js.log(result2##value);
