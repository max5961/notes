import { CakeActions } from "./cakeActions";

export type CakeState = {
    numCakes: number;
};

const initState: CakeState = {
    numCakes: 10,
} as const;

function cakeReducer(
    state: CakeState = initState,
    action: CakeActions,
): CakeState {
    if (action.type === "BUY_CAKE") {
        return {
            ...state,
            numCakes: state.numCakes - 1,
        };
    }

    return state;
}

export default cakeReducer;
