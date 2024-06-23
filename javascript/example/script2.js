const p = new Promise((res) => {
    console.log("1");
    res("2");
    console.log("3");
})
    .then(console.log);

console.log(p);
console.log("4");

// 1, 3, promise {<pending>}, 4, 2

