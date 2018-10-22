open Sqlite;

let db = makeDatabase("test.db", ~memory=true, ());

let result = db->Database.prepare("select 1 + 2 as value")->Statement.get();
Js.log(result##value);

let result2 =
  db
  ->Database.prepare("select $a + $b - $c as value")
  ->Statement.getWithArgs({"a": 44, "b": 22, "c": 11});
Js.log(result2##value);

let result3 =
  db
  ->Database.prepare("select :x  * :y as value")
  ->Statement.getWithArgs({"x": 5, "y": 6});
Js.log(result3##value);
