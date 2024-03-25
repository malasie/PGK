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
        private ICollision collAlg;
        
        public SimulationBox(IAlg a, IAlg a2, ICollision c)
        {
            alg = a;
            alg2 = a2;
            collAlg = c;
        }

        public int Height { get; set; }
        public int Width { get; set; }

        public List<Ball> Balls { get; private set; } = new List<Ball>();

        public List<Collision> collist { get; set; } = new List<Collision>();

        public void addBall(Ball ball)
        {
            Balls.Add(ball);
        }

        public void NextStep()
        {
            alg.NextStep(Balls, Width);

            alg2.NextStep(Balls, Height);
        }

        public void CollAlg()
        {
            collAlg.CollAlg(Balls, collist);
        }
    }
}
