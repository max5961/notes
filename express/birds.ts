import express, { Request, Response } from "express";
export const router = express.Router();

router.use((req: Request, res: Response, next) => {
    console.log(`Time: ${Date.now()}`);
    next();
});

router.get("/", (req: Request, res: Response) => {
    res.send("Birds home page");
});

router.get("/about", (req: Request, res: Response) => {
    res.send("Birds about");
});
