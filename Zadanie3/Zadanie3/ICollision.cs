using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zadanie3
{
    internal interface ICollision
    {
        void CollAlg(List<Ball> balls, List<Collision> collist);
    }
}