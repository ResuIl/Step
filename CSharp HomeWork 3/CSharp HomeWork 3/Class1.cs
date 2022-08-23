using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_HomeWork_3 {
    class Counter {
        private int min;
        private int max;
        private int currentData;


        public Counter(int _min, int _max) {
            min = _min;
            max = _max;
            currentData = _min;
        }

        public void Increment() {
            if (currentData < max)
                currentData++;
            else currentData = min;

        }
        public void Decrement() {
            if (currentData > min)
                currentData--;
            else currentData = max;
        }

        public int getCurrent() { return currentData; }
    }
}
