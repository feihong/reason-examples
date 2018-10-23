open Belt;
open Sqlite;

let db = makeDatabase("test.db", ~timeout=1000, ());

let createSql = {|
  DROP TABLE IF EXISTS players;

  CREATE TABLE players (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username VARCHAR(100),
    level INTEGER
  );
|};
db->Database.exec(createSql);

let insert =
  db->Database.prepare("INSERT INTO players VALUES ($id, $username, $level)");

/* let insertMany =
   db->Database.transaction(rows =>
     rows
     ->List.map(row => {
         let (id, username, level) = row;
         insert->Statement.runWithArgs({
           "id": id,
           "username": username,
           "level": level,
         });
       })
     ->Js.log
   ); */

let insertMany = rows =>
  rows->List.map(row => {
    let (id, username, level) = row;
    insert->Statement.runWithArgs({
      "id": id,
      "username": username,
      "level": level,
    });
  });

insertMany([
  (1001, "Cowman", 45),
  (1002, "Batgirl", 800),
  (1003, "Manateewoman", 9000),
])
->Js.log;

let result =
  db
  ->Database.prepare("SELECT SUM(level) as totalLevel FROM players")
  ->Statement.get()
  ->Js.log;

db->Database.close();
