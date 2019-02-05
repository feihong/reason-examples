/* https://stackoverflow.com/questions/9323036/tail-recursive-function-to-find-depth-of-a-tree-in-ocaml/9328844#9328844 */

type tree =
  | Leaf(int)
  | Node(int, tree, tree);

/* non-tail recursive */
let rec ntcTraverse = tree =>
  switch (tree) {
  | Leaf(x) => [x]
  | Node(x, l, r) =>
    let lst = List.concat(ntcTraverse(l), ntcTraverse(r));
    [x, ...lst];
  };

/* tail recursive */
let rec traverse = (acc, stack) =>
  switch (stack) {
  | [] => acc->List.reverse
  | [Leaf(x), ...t] => traverse([x, ...acc], t)
  | [Node(x, l, r), ...t] =>
    let acc' = [x, ...acc];
    let stack' = [l, r, ...t];
    traverse(acc', stack');
  };

/* slight optimization using mutable queue */
let qTraverse = tree => {
  module Q = MutableQueue;
  let acc = Q.make();

  let rec aux = stack =>
    switch (stack) {
    | [] => ()
    | [Leaf(x), ...t] =>
      acc->Q.add(x);
      aux(t);
    | [Node(x, l, r), ...t] =>
      acc->Q.add(x);
      aux([l, r, ...t]);
    };

  let () = aux([tree]);
  acc->Q.toArray;
};

let myTree =
  Node(
    1,
    Node(2, Node(4, Leaf(41), Leaf(42)), Node(6, Leaf(61), Leaf(62))),
    Node(3, Node(5, Leaf(51), Leaf(52)), Node(7, Leaf(71), Leaf(72))),
  );

ntcTraverse(myTree)->List.toArray->Js.log;
traverse([], [myTree])->List.toArray->Js.log;
qTraverse(myTree)->Js.log;
