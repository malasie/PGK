using System.Collections.Generic;

namespace Zad2
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

        public void nextStep()
        {
            alg.calcNextStep(Balls);

            alg2.calcNextStep(Balls);
        }
    }

}
