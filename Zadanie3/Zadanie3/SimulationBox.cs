using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zadanie3
{
    internal class SimulationBox
    {
        private IAlg alg;
        private IAlg alg2;
        public SimulationBox(IAlg a, IAlg a2)
        {
            alg = a;
            alg2 = a2;
        }

        public int Height { get; set; }
        public int Width { get; set; }

        public List<Ball> Balls { get; private set; } = new List<Ball>();
        public void addBall(Ball ball)
        {
            Balls.Add(ball);
        }

        public void NextStep()
        {
            alg.NextStep(Balls, Width);

            alg2.NextStep(Balls, Height);
        }
    }
}
