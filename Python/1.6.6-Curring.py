# Curring函数,将f(x,y)转换为g(x)(y)的形式
def curried_pow(x):
  def h(y):
    return pow(x,y)
  return h

def map_to_range(start,end,f):
  while start < end:
    print(f(start))
    start = start + 1
    
def curry2(f):
  """
    Return a curried version of the given two-argument function
  """
  def g(x):
    def h(y):
      return f(x,y)
    return h
  return g

  
def uncurry2(g):
  def f(x,y):
    return g(x)(y)
  return f
  
pow_curried = curry2(pow)
print(pow_curried(2)(5))

print(map_to_range(0,10,pow_curried(2)))

print(uncurry2(pow_curried)(2,5))