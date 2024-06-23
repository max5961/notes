import React from "react";
import { connect } from "react-redux";
import { CakeState } from "../redux/cake/cakeReducer";
import redux, { UnknownAction } from "redux";
import { buyCake } from "../redux/cake/cakeActions";

interface Props {
    numCakes: number;
    buyCake(): void;
}

function CakeContainer(props: Props): React.ReactNode {
    return (
        <div>
            <h2>Number of Cakes - {props.numCakes}</h2>
            <button onClick={props.buyCake}>Buy Da Cake</button>
        </div>
    );
}

function mapStateToProps(state: CakeState): CakeState {
    return {
        numCakes: state.numCakes,
    };
}

function mapDispatchToProps(dispatch: redux.Dispatch) {
    return {
        buyCake: () => dispatch(buyCake() as UnknownAction),
    };
}

export default connect(mapStateToProps, mapDispatchToProps)(CakeContainer);
