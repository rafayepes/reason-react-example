/*
   TODO
     - Find out about the board Square.Square.square type
     - Find out about how to generate keys for list items.
     - Attach click handler and find out how to properly update the board.
 */
module Board = {
  include ReactRe.Component.Stateful;
  type board = list (list Square.Square.square);
  /*include ReactRe.Com*/
  type props = {size: int};
  /* TODO find out why do I need to put Square.Square.square instead ofSquare.square */
  type state = {board};
  let name = "Board";
  let rec generateRow_inner: (int, int, int) => list Square.Square.square =
    fun
    | (0, _, _) => []
    | (x, y, z) => [Empty (z - y, z - x), ...generateRow_inner (x - 1, y, z)];
  let generateRow (size, counter) => generateRow_inner (size, counter, size);
  let rec generateBoard_inner =
    fun
    | (0, _)
    | (_, 0) => [[]]
    | (size, counter) => [generateRow (size, counter), ...generateBoard_inner (size, counter - 1)];
  let generateBoard size => generateBoard_inner (size, size);
  let getInitialState {size} => {board: generateBoard size};
  let onSquareClick {state} point =>
    switch point {
    | (x, y) =>
      Js.log ("[" ^ string_of_int x ^ "," ^ string_of_int y ^ "]");
      Some {
        board:
          List.mapi
            (
              fun i row =>
                if (i == x) {
                  List.mapi
                    (
                      fun j item =>
                        if (j == y) {
                          Square.Square.Cross (x, y)
                        } else {
                          item
                        }
                    )
                    row
                } else {
                  row
                }
            )
            state.board
      }
    };
  let rec renderRow ::row ::onSquareClick =>
    switch row {
    | [] => [ReactRe.nullElement]
    | [hd, ...tl] =>
      switch hd {
      | Square.Square.Empty (x, y)
      | Square.Square.Nought (x, y)
      | Square.Square.Cross (x, y) => [
          <Square
            key=(string_of_int x ^ "," ^ string_of_int y)
            content=hd
            onClick=onSquareClick
          />,
          ...renderRow row::tl ::onSquareClick
        ]
      }
    };
  let rec renderBoard ::board ::onSquareClick =>
    switch board {
    | [] => ReactRe.nullElement
    | [hd, ...tl] =>
      switch hd {
      | [] => ReactRe.nullElement
      | _ =>
        ReactRe.listToElement [
          <Row> (ReactRe.listToElement (renderRow row::hd ::onSquareClick)) </Row>,
          renderBoard board::tl ::onSquareClick
        ]
      }
    };
  let render {props, state, updater} =>
    <div> (renderBoard board::state.board onSquareClick::(updater onSquareClick)) </div>;
};

include ReactRe.CreateComponent Board;

let createElement ::size => wrapProps {size: size};
