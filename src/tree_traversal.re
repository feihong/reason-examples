/* https://stackoverflow.com/questions/9323036/tail-recursive-function-to-find-depth-of-a-tree-in-ocaml/9328844#9328844 */
open Belt;

type tree =
  | Leaf(int)
  | Node(int, tree, tree);

let rec traverse = (acc, stack) =>
  switch (stack) {
  | [] => acc->List.reverse
  | [Leaf(x), ...t] => traverse([x, ...acc], t)
  | [Node(x, l, r), ...t] =>
    let acc' = [x, ...acc];
    let stack' = [l, r, ...t];
    traverse(acc', stack');
  };

let myTree =
  Node(
    1,
    Node(2, Node(4, Leaf(41), Leaf(42)), Node(6, Leaf(61), Leaf(62))),
    Node(3, Node(5, Leaf(51), Leaf(52)), Node(7, Leaf(71), Leaf(72))),
  );

traverse([], [myTree])->List.toArray->Js.log;
