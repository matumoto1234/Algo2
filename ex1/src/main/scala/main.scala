import scala.io.StdIn.{readInt, readLine}

object Main {
  def main(args: Array[String]): Unit = {
    val n = readInt()
    val as = readLine().split(" ").map(_.toInt).toVector
  }
}

case class Sorter() {
  def merge(left: Vector[Int], right: Vector[Int]): Vector[Int] = {
    val infinity = Int.MaxValue / 2
    val maxLength = Vector(left.length, right.length).max
    val newLeft = left.padTo(maxLength, infinity)
    val newRight = right.padTo(maxLength, infinity)
    (newLeft, newRight) match {
      (l)
    }
  }

  def mergeSort(vs: Vector[Int]): Vector[Int] = {
    if (vs.length == 1) {
      return vs
    }
    val mid = vs.length / 2
    val (lvs, rvs) = vs.splitAt(mid)
    return lvs
  }
}

object Sorter {
}
