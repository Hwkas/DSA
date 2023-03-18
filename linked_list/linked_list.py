class LinkNode:
    def __init__(self, value = None, next = None):
        self.value = value
        self.next = next


# First linked list 
l1 = LinkNode(2)
l2 = LinkNode(4)
l1.next = l2
l3 = LinkNode(3)
l2.next = l3

# Second linked list
ll1 = LinkNode(5)
ll2 = LinkNode(6)
ll1.next = ll2
ll3 = LinkNode(4)
ll2.next = ll3


cur1 = l1
cur2 = ll1 

while(cur1):
    print(cur1.value, end=" ")
    cur1 = cur1.next
print()

while(cur2):
    print(cur2.value, end=" ")
    cur2 = cur2.next

print()




def sum_of_list(l1, l2):
    
        result = LinkNode(0)
        result_tail = result
        carry = 0
                
        while l1 or l2 or carry:            
            val1  = (l1.value if l1 else 0)
            val2  = (l2.value if l2 else 0)
            carry, out = divmod(val1+val2 + carry, 10)    
                      
            result_tail.next = LinkNode(out)
            result_tail = result_tail.next                      
            
            l1 = (l1.next if l1 else None)
            l2 = (l2.next if l2 else None)
               
        return result.next

s = sum_of_list(l1, ll1)

while (s):
    print(s.value)
    s = s.next

