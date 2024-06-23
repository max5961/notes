import mongoose, { Schema } from "mongoose";

const numberSchema = new Schema({
    integerOnly: {
        type: Number,
        get: (v) => Math.round(v),
        set: (v) => Math.round(v),
        alias: "i",
    },
});

const NumberModel = mongoose.model("NumberModel", numberSchema);

const doc = new NumberModel();
doc.integerOnly = 2.001;
console.log(doc.integerOnly); // 2
console.log(doc.i); // 2

doc.i = 3.001;
console.log(doc.integerOnly); // 3
console.log(doc.i); // 3
