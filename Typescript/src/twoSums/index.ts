function twoSum(nums: number[], target: number): number[] {
    const hasher = new Map<number, number>()
    
    for (let index = 0; index < nums.length; index++) {
        if(hasher.has(nums[index])) {
            return [hasher.get(nums[index])!, index]
        }
        hasher.set(target-nums[index], index)
    }

    return []
};

const teste1 =  {
    valores: [2,7,11,15],
    target: 9
}

twoSum(teste1.valores, teste1.target)
