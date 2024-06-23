import express, { Request, Response } from "express";
import path from "path";
import fs from "fs/promises";

const app = express();
const PORT: number = Number(process.env.PORT) || 3000;

app.use((req, res, next) => {
    try {
        throw new Error("broken!");
    } catch (err) {
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
