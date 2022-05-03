
namespace RandomCS
{
    class Random
    {
        public double random_value;
        public Random()
        {
            this.Randomize();
        }
        public double Randomize()
        {
            this.random_value = new System.Random().NextDouble();
            return this.random_value;
        }
        public double getValue()
        {
            return this.random_value;
        }
        public double Range(double min = 0.0, double max = 1.0)
        {
            return min + (this.random_value * (max - min));
        }
        public int iRange(int min = 0, int max = 1)
        {
            return (int)(this.Range(min, max));
        }
        public string Choice(System.Array array)
        {
            return array.GetValue(this.iRange(0, array.Length)).ToString();
        }
        public System.Array Choices(System.Array array, int length)
        {
            string[] rarray = new string[length];
            for (int i=0; i < length ;i++)
            {
                rarray[i] = this.Choice(array);
                this.Randomize();
            }
            return rarray;
        }
        protected string ConvertArrayToString(System.Array array)
        {
            string _str = "";
            foreach (string arr in array)
            {
                _str += arr;
            }
            return _str;
        }
        public string StringRange(int length, string addchars = "")
        {
            return this.ConvertArrayToString(this.Choices(("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"+addchars).ToCharArray(), length));
        }
    }
}
