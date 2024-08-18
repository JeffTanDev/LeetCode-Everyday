dic={
        1:'I',
        4:'IV',
        5:'V',
        9:'IX',
    }

def hash(data):
    ans=''
    while data:
        max=0
        val=''
        for key, value in dic.items():
            if key>max and key<=data:
                max=key
                val=value
        data-=max
        ans+=val
    return ans

def main():
    user_input=input()
    ans=hash(int(user_input))
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()
