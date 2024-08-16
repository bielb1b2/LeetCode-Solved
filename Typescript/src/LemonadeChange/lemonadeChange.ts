function lemonadeChange(bills: number[]): boolean {
    let bill5 = 0;
    let bill10 = 0;

    // List vazia
    if (bills.length < 1) {
        return false;
    }

    // Percorre
    for (let item = 0; item < bills.length; item++) {
        switch (bills[item]) {
            case 5:
            bill5++;
            break

            case 10:
            bill10++;
            if(bill5 <= 0) {
                return false;
            }
            bill5--;
            break

            case 20:
            if(bill5 <= 0) {
                return false;
            }

            if(bill10 > 0) {
                bill10--;
                bill5--;
                break
            }

            if(bill5 >= 3) {
                bill5 -= 3;
                break
            }
            
            return false;

            default:
                return false;
        }
    }

    return true;
};

const case1 = [5, 5, 5, 10, 20]
const case2 = [5, 5, 10, 10, 20]
const case3 = [5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5]

console.table([
        lemonadeChange(case1), // True
        lemonadeChange(case2), // False
        lemonadeChange(case3) // True
])
