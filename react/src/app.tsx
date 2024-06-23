import React from "react";
import { useState, useMemo, useCallback } from "react";

export default function App() {
    const [count, setCount] = useState<number>(0);

    // const handleClick = useCallback(() => {
    //     setCount((count) => count + 1);
    // }, []);

    const handleClick = useMemo(() => {
        return () => {
            setCount((count) => count + 1);
        };
    }, []);

    return (
        <>
            <p>{count}</p>
            <MyButton handleClick={handleClick} />
        </>
    );
}

interface MyButtonProps {
    handleClick(): void;
}
const MyButton = React.memo(
    ({ handleClick }: MyButtonProps): React.ReactNode => {
        console.log("Rendered");
        return <button onClick={handleClick}>Increase</button>;
    },
);
