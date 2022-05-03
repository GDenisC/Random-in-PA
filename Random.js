class Random
{
    constructor()
    {
        this.a = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"
    }
    addchars = function(chars)
    {
        this.a += chars
    }
    range = function(min, max)
    {
        return min + (Math.random() * (max - min))
    }
    irange = function(min, max)
    {
        return Math.round(this.range(min, max))
    }
    str = function(l)
    {
        var r = ""
        var b = this.a.split("")
        for (var i = 0; i < l ; i++)
        {
            var result = this.a[this.irange(0, b.length)]
            if (result != undefined)
            {
                r += result
            }
            else
            {
                i -= 1
                continue 
            }
        }
        return r
    }
    choice = function(words)
    {
        //let w = undefined
        //while (true)
        //{
        return words[this.irange(0,words.length-1)]
        //    if (w != undefined)
        //    { break }
        //}
        //return w
    }
    choices = function(words, length)
    {
        let rs = []
        for (let i=0; i < length; i++)
        {
            rs[i] = this.choice(words)
        }
        return rs
    }
    join = function(str, arr)
    {
        let r = ""
        for (let i=0; i<arr.length; i++)
        {
            r += str + arr[i]
        }
        return r.slice(str.length)
    }
}
