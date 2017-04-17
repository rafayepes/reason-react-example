module Row = {
  include ReactRe.Component;
  /*include ReactRe.Com*/
  /*TODO find out wtf I need to put Square module twice there*/
  /*type props = {children: list Square.Square.square, onClick: None};*/
  /*type props = {children: list Square.Square.square};*/
  type props = {children: list ReactRe.reactElement};
  let name = "Row";
  let handleClick _ _ => {
    /*let content =
      switch props.content {
      | None => (ReactRe.stringToElement "[_]")
      | Cross => (ReactRe.stringToElement "[x]")
      | Square => (ReactRe.stringToElement "[o]")
      };*/
    /*let a = ("a", "b");*/
    /*JS.log (a [1]);*/
    Js.log "clicked 22222!";
    None
  };
  /*let render {props, updater} => <div> props.children </div>;*/
  let render {props, updater} =>
    <div style=(ReactDOMRe.Style.make display::"flex" flexDirection::"row" ())>
      (ReactRe.listToElement props.children)
    </div>;
};

include ReactRe.CreateComponent Row;

/*switch props.content {
  | [] => ReactRe.nullElement
  | Cross => ReactRe.stringToElement "[x]"
  | Square => ReactRe.stringToElement "[o]"
  }*/
/*(ReactRe.stringToElement "[o][x][_]")*/
let createElement ::children => wrapProps {children: children} ::children;
