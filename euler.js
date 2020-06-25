problems = []

function add_runable(f)
{
    problems.push(f);
}

// utility functions
function get_prime_factors(n)
{
    factors = [];

    if (n % 2 === 0)
    {
        while (n % 2 === 0)
        {
            factors.push(2);
            n /= 2;
        }
    }

    max = Math.sqrt(n)
    for (let i = 3; i < max; ++i)
    {
        if (n % i === 0)
        {
            while (n % i === 0)
            {
                factors.push(i);
                n /= i;
            }
        }
    }

    if (n > 2)
    {
        factors.push(i);
    }

    return factors
}

// the problems
add_runable(
    function problem_1()
    {
        description = [
            "https://projecteuler.net/problem=1",
            "If we list all the natural numbers below 10 that are multiples of 3 or 5,",
            "we get 3, 5, 6 and 9. The sum of these multiples is 23.",
            "",
            "Find the sum of all the multiples of 3 or 5 below 1000. ",
        ];

        console.log(description.join("\n"));

        let N = Math.round(999 / 3)
        let Q = Math.round(999 / 5)
        let R = Math.round(999 / 15)
        let _3sum = (N * (N + 1)) / 2
        let _5sum = (Q * (Q + 1)) / 2
        let _15sum = (R * (R + 1)) / 2
        return 3 * _3sum + 5 * _5sum - 15 * _15sum
    }
)

add_runable
(
    function problem_2()
    {
        description = [
            "https://projecteuler.net/problem=2",
            "Each new term in the Fibonacci sequence is generated by adding the previous two terms.",
            "By starting with 1 and 2, the first 10 terms will be",
            "",
            "\t1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...",
            "",
            "By considering the terms in the Fibonacci sequence whose values do not exceed four million,",
            "find the sum of the even-valued terms."
        ];

        console.log(description.join("\n"));

        let a = 0
        let b = 1
        let sum = 0
        while (b <= 4e6)
        {
            if (b % 2 === 0)
            {
                sum += b;
            }
            let c = b + a;
            a = b;
            b = c;
        }
        return sum;
    }
)

add_runable
(
    function problem_3()
    {
        description = [
            "https://projecteuler.net/problem=3",
            "The prime factors of 13195 are 5, 7, 13 and 29.",
            "",
            "What is the largest prime factor of the number 600851475143?"
        ];

        console.log(description.join("\n"));

        return get_prime_factors(600851475143).pop();
    }
)

problems.forEach((runnable) => console.log(`result: ${runnable()}`));