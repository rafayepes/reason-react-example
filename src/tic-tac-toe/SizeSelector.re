/*
   TODO
     - Find out about the board Square.Square.square type
     - Find out about how to generate keys for list items.
     - Attach click handler and find out how to properly update the board.
 */
module SizeSelector = {
  include ReactRe.Component;
  /*include ReactRe.Com*/
  type props = {size: int, onChangeSize: ReactEventRe.Form.t => unit};
  /* TODO find out why do I need to put Square.Square.square instead ofSquare.square */
  let name = "SizeSelector";
  let handleInputChange {props} event =>
    props.onChangeSize (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##value;
  let render {props, handler} =>
    <input _type="number" onChange=props.onChangeSize value=(string_of_int props.size) />;
  /*let render {props, state, updater} => <input type="number" value=(props.size) />;*/
};

include ReactRe.CreateComponent SizeSelector;

let createElement ::size ::onChangeSize => wrapProps {size, onChangeSize};
