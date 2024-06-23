export interface CakeActions {
    type: "BUY_CAKE";
}

export function buyCake(): CakeActions {
    return {
        type: "BUY_CAKE",
    };
}
