"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const redux_1 = require("redux");
const redux_thunk_1 = __importDefault(require("redux-thunk"));
const axios_1 = __importDefault(require("axios"));
const initState = {
    loading: false,
    users: [],
    error: "",
};
function fetchUsersRequest() {
    return {
        type: "FETCH_USERS_REQUEST",
    };
}
function fetchUsersSuccess(users) {
    return {
        type: "FETCH_USERS_SUCCESS",
        payload: users,
    };
}
function fetchUsersFailure(err) {
    return {
        type: "FETCH_USERS_FAILURE",
        payload: err,
    };
}
function reducer(state = initState, action) {
    if (action.type === "FETCH_USERS_REQUEST") {
        return Object.assign(Object.assign({}, state), { loading: true });
    }
    if (action.type === "FETCH_USERS_SUCCESS") {
        return Object.assign(Object.assign({}, state), { loading: false, users: action.payload, error: "" });
    }
    if (action.type === "FETCH_USERS_FAILURE") {
        return Object.assign(Object.assign({}, state), { loading: false, users: [], error: action.payload });
    }
    return state;
}
function fetchUsers() {
    return (dispatch) => {
        dispatch(fetchUsersRequest());
        axios_1.default
            .get("https://jsonplaceholder.typicode.com/users")
            .then((res) => {
            const users = res.data.map((user) => user.id);
            dispatch(fetchUsersSuccess(users));
        })
            .catch((err) => {
            dispatch(fetchUsersFailure(err.message));
        });
    };
}
const store = (0, redux_1.createStore)(reducer, (0, redux_1.applyMiddleware)(redux_thunk_1.default));
store.subscribe(() => {
    console.log(store.getState());
});
store.dispatch(fetchUsers());
