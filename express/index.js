"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const express_1 = __importDefault(require("express"));
const app = (0, express_1.default)();
const PORT = Number(process.env.PORT) || 3000;
app.use((req, res, next) => {
    try {
        throw new Error("broken!");
    }
    catch (err) {
        next(err);
    }
});
app.get("/", (req, res) => {
    res.send("eyy we good now error was handled");
});
app.get("/brodude", (req, res) => res.send("brodude"));
app.listen(PORT, () => {
    console.log(`Example app listening on port ${PORT}`);
});
