# https://stackoverflow.com/a/60956561/5217293
def register_problem(f):
    """
    Creates an attribute on the method, so it can
    be identied as a function to call
    """
    f._is_problem = True
    return f

class Problems:
    def __init__(self):
        self.problem_methods = {}
        for name in dir(self):
            attr = getattr(self,name)
            if getattr(attr,"_is_problem",False):
                self.problem_methods[name] = attr

    def run(self):
        for _,method in self.problem_methods.items():
            print("="*40)
            print(method.__doc__)
            print(f"\tResult: {method()}")
            print("="*40)
            print()

    @register_problem
    def __1(self):
        """\thttps://projecteuler.net/problem=1
        If we list all the natural numbers below 10 that are multiples of 3 or 5, 
        we get 3, 5, 6 and 9. The sum of these multiples is 23.

        Find the sum of all the multiples of 3 or 5 below 1000.
        """

        return sum([i for i in range(1000) if i % 3 == 0 or i % 5 == 0])