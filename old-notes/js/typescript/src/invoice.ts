export class Invoice {
    constructor(
        public client: string,
        public details: string,
        public amount: number
    ){}

    format(): string {
        return this.client + this.details;
    }
}
