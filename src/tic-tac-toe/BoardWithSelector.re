module BoardSizeSelector = {
  include ReactRe.Component.Stateful;
  type props = {initialSize: int};
  type state = {size: int};
  let getInitialState {initialSize} => {size: initialSize};
  let onSizeChange _ event => {
    let value = (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##value;
    Js.log value;
    Some {size: value}
  };
  let name = "BoardSizeSelector";
  let render {state, updater} => {
    Js.log "foo";
    Js.log state.size;
    <div>
      <SizeSelector size=state.size onChangeSize=(updater onSizeChange) />
      <Board size=state.size />
    </div>
  };
};

/*<SizeSelector size=state.size /> */
include ReactRe.CreateComponent BoardSizeSelector;

let createElement ::initialSize => wrapProps {initialSize: initialSize};
