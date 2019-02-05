open Prelude.Utils;

/* Return all rotations of a list */
let rotations = lst => {
  let len = lst->List.length;
  let rec aux = (acc, i, lst) =>
    switch (i) {
    | i when i >= len => acc->List.reverse
    | i =>
      let (a, b) = lst->List.splitAt(i)->Option.getWithDefault(([], []));
      let acc' = [List.concat(b, a), ...acc];
      aux(acc', i + 1, lst);
    };
  aux([], 0, lst);
};

rotations([1])->logList;
rotations([1, 2, 3])->logList;
rotations([1, 2, 3, 4])->logList;
