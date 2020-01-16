using System.Collections.Generic;
using System.Collections;
using System.Windows.Forms;
using System.Drawing;
using System.Drawing.Drawing2D;
namespace D16TH05
{
    public class Variable
    {
        private int _numbervertex;
        private List<int> _vertex;
        private List<Button> _buttonvertex;
        private List<List<int>> _matrixadjacent;
        private Hashtable _listadjacent;
        private List<List<int>> _matrix;
        private Bitmap _bmpGraphics;
        private List<Point> _lpoint;
        private string _sdijkstra;
        private int[,] _lcaykhungnn;
        private int _socanh;
        private int _chon;
        private List<int> _dfs;
        private List<int> _bfs;

        public int numbervertex
        {
            get { return _numbervertex; }
            set { _numbervertex = value; }
        }
        public List<int> vertex
        {
            get { return _vertex; }
            set { _vertex = value; }
        }
        public List<Button> buttonvertex
        {
            get { return _buttonvertex; }
            set { _buttonvertex = value; }
        }
        public List<List<int>> matrixadjacent
        {
            get { return _matrixadjacent; }
            set { _matrixadjacent = value; }
        }
        public Hashtable listadjacent
        {
            get { return _listadjacent; }
            set { _listadjacent = value; }
        }
        public List<List<int>> matrix
        {
            get { return _matrix; }
            set { _matrix = value; }
        }
        public Bitmap bmggraphics
        {
            get { return _bmpGraphics; }
            set { _bmpGraphics = value; }
        }
        public List<Point> lpoint
        {
            get { return _lpoint; }
            set { _lpoint = value; }
        }
        public string sdijkstra
        {
            get { return _sdijkstra; }
            set { _sdijkstra = value; }
        }
        public int[,] lcaykhungnn
        {
            get { return _lcaykhungnn; }
            set { _lcaykhungnn = value; }
        }
        public int socanh
        {
            get { return _socanh; }
            set { _socanh = value; }
        }
        public int chon
        {
            get { return _chon; }
            set { _chon = value; }
        }
        public List<int> dfs
        {
            get { return _dfs; }
            set { _dfs = value; }
        }
        public List<int> bfs
        {
            get { return _bfs; }
            set { _bfs = value; }
        }
    }
}
