const bro = {
    a: "a",
    b: "b",
    c: "c",
}

Object.seal(bro);
console.log(Object.isSealed(bro)); // true

for (const k of Object.keys(bro)) {
    // THIS WILL MODIFY 'bro' THE KEYS ARE NOT IMMUTABLE
    bro[k] = "MOD";
}

bro.d = "MOD"; // DOESN'T GET ADDED, 'bro' IS SEALED!!!
delete bro.c;  // DOESN'T GET DELETED, 'bro' IS SEALED!!!

console.log(bro); // logs { a: 'MOD', b: 'MOD', c: 'MOD' }



