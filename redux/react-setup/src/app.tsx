import React from "react";
import { useState } from "react";
import { Provider } from "react-redux";
import CakeContainer from "./components/CakeContainer";
import store from "./redux/store";

export default function App() {
    return (
        <Provider store={store}>
            <div className="app">
                <CakeContainer />
            </div>
        </Provider>
    );
}
