module Square = {
  include ReactRe.Component;
  type boardPosition = (int, int);
  /*include ReactRe.Com*/
  type square =
    | Empty boardPosition
    | Nought boardPosition
    | Cross boardPosition;
  type props = {content: square, onClick: boardPosition => unit};
  let name = "Square";
  let handleClick {props: {content, onClick}} _ => {
    switch content {
    | Empty boardPosition
    | Nought boardPosition
    | Cross boardPosition => onClick boardPosition
    };
    None
  };
  /*None*/
  /*let content =
    switch props.content {
    | None => (ReactRe.stringToElement "[_]")
    | Cross => (ReactRe.stringToElement "[x]")
    | Square => (ReactRe.stringToElement "[o]")
    };*/
  /*let a = ("a", "b");*/
  /*JS.log (a [1]);*/
  /*Js.log "clicked 22222!";*/
  /*None*/
  let renderSquare ::content ::onClick => {
    let squareValue =
      switch content {
      | Empty _ => "[_]"
      | Cross _ => "[x]"
      | Nought _ => "[o]"
      };
    <div onClick> (ReactRe.stringToElement squareValue) </div>
  };
  let render {props, updater} =>
    renderSquare content::props.content onClick::(updater handleClick);
};

include ReactRe.CreateComponent Square;

let createElement ::content ::onClick => wrapProps {content, onClick};
