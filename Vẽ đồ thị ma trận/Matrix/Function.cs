using System;
using System.Collections.Generic;
using System.Collections;
using System.Windows.Forms;
using System.IO;
using System.Drawing;
namespace D16TH05
{
    public class Function : Form
    {
        public Variable variable = new Variable();
        public ColumnHeader AddColumn(string text)
        {
            ColumnHeader temp = new ColumnHeader();
            temp.Text = text;
            temp.Width = 10;
            temp.TextAlign = HorizontalAlignment.Center;
            temp.AutoResize(ColumnHeaderAutoResizeStyle.HeaderSize);
            return temp;
        }

        public List<List<int>> LoadFileMatrix(string filename, ListView lv)
        {
            List<List<int>> lltemp = new List<List<int>>();
            StreamReader fin = new StreamReader(filename);
            variable.numbervertex = Convert.ToInt32(fin.ReadLine());
            lv.Columns.Add(AddColumn(variable.numbervertex.ToString()));
            List<int> row;
            for (int i = 0; i < variable.numbervertex; i++)
            {
                string line = fin.ReadLine();
                string[] world = line.Split(' ');
                lv.Columns.Add(AddColumn((i + 1).ToString()));
                ListViewItem lvi = new ListViewItem((i + 1).ToString());
                lvi.UseItemStyleForSubItems = false;
                row = new List<int>();
                for (int j = 0; j < variable.numbervertex; j++)
                {
                    ListViewItem.ListViewSubItem col = lvi.SubItems.Add(world[j]);
                    col.ForeColor = Color.Blue;
                    row.Add(Convert.ToInt32(world[j]));
                }
                lltemp.Add(row);
                lv.Items.Add(lvi);
            }
            variable.matrixadjacent = lltemp;
            fin.Close();
            return variable.matrixadjacent;
        }

        public Hashtable LoadFileList(string filename, ListView lv)
        {
            StreamReader fin = new StreamReader(filename);
            variable.numbervertex = Convert.ToInt32(fin.ReadLine());
            lv.Columns.Add(AddColumn(variable.numbervertex.ToString()));
            lv.Columns.Add(AddColumn("tất cả các đỉnh khác có cạnh nối với đỉnh"));
            Hashtable htemp = new Hashtable();
            for (int i = 0; i < variable.numbervertex; i++)
            {
                string line = fin.ReadLine();
                ListViewItem lvi = new ListViewItem((i + 1).ToString());
                lvi.UseItemStyleForSubItems = false;
                htemp.Add(i, line);
                ListViewItem.ListViewSubItem col = lvi.SubItems.Add(line);
                col.ForeColor = Color.Blue;
                lv.Items.Add(lvi);
            }
            fin.Close();
            variable.listadjacent = htemp;
            return variable.listadjacent;
        }

        public Hashtable MatrixToList(Variable variable, ListView lv)
        {
            lv.Columns.Add(AddColumn(variable.numbervertex.ToString()));
            lv.Columns.Add(AddColumn("tất cả các đỉnh khác có cạnh nối với đỉnh"));
            Hashtable hbtemp = new Hashtable();
            for (int i = 0; i < variable.numbervertex; i++)
            {
                string world = "";
                ListViewItem lvi = new ListViewItem((i + 1).ToString());
                lvi.UseItemStyleForSubItems = false;
                for (int j = 0; j < variable.numbervertex; j++)
                {
                    if (variable.matrixadjacent[i][j] != 0)
                        world += (j + 1).ToString() + " " + variable.matrixadjacent[i][j].ToString() + " ";
                }
                ListViewItem.ListViewSubItem col = lvi.SubItems.Add(world);
                //col.ForeColor = Color.Blue;
                lv.Items.Add(lvi);
                hbtemp.Add(i, world);
            }
            variable.listadjacent = hbtemp;
            return variable.listadjacent;
        }

        public List<List<int>> ListToMatrix(Variable variable, ListView lv)
        {
            List<List<int>> lltemp = new List<List<int>>();
            lv.Columns.Add(AddColumn(variable.numbervertex.ToString()));
            List<int> row;
            for (int i = 0; i < variable.numbervertex; i++)
            {
                string line = variable.listadjacent[(i)].ToString() + " " + "0";
                string[] world = line.Split(' ');
                lv.Columns.Add(AddColumn((i + 1).ToString()));
                ListViewItem lvi = new ListViewItem((i + 1).ToString());
                row = new List<int>();
                int n = 0;
                for (int j = 1; j <= variable.numbervertex; j++)
                {
                    if (world[n] == j.ToString() && n < world.Length - 2)
                    {
                        lvi.SubItems.Add(world[n + 1]);
                        row.Add(Convert.ToInt32(world[n + 1]));
                        n += 2;
                    }
                    else
                    {
                        lvi.SubItems.Add("0");
                        row.Add(0);
                    }
                }
                lltemp.Add(row);
                lv.Items.Add(lvi);
            }
            variable.matrixadjacent = lltemp;
            return variable.matrixadjacent;
        }

        public List<Point> RandomVertex(Variable variable)
        {
            List<Point> ltemp = new List<Point>();
            Random ramdom = new Random();
            for (int i = 0; i < variable.numbervertex; i++)
            {
                    Point ptemp = new Point(ramdom.Next(100,400), ramdom.Next(100, 400));
                    ltemp.Add(ptemp);
            }
            variable.lpoint = ltemp;
            return variable.lpoint;
        }
        public Bitmap GraphicsTools()
        {
            return variable.bmggraphics = new Bitmap(500, 500);
        }
        private void DrawLine(Graphics g, Pen pLine, Point ptStart, Point ptEnd)
        {
            g.DrawLine(pLine, ptStart, ptEnd);
        }
        private void DrawVertex(Graphics g, Brush bFillNode, Pen pEllipse, Rectangle rect, Point pt, string name)
        {
            g.FillEllipse(bFillNode, rect);
            g.DrawEllipse(pEllipse, rect);
            Font stringFont = new Font("Arial", 9);
            SizeF stringSize = g.MeasureString(name, stringFont);
            g.DrawString(name, stringFont, Brushes.Black, pt.X + (20 - stringSize.Width) / 2, pt.Y + (20 - stringSize.Height) / 2);
        }
        public Bitmap Drawcaykhung(Variable variable)
        {
            Graphics g = Graphics.FromImage(variable.bmggraphics);
            Pen p = new Pen(Color.Black, 2);
            Point ptStart, ptEnd;
            for(int i=1;i<=variable.socanh;i++)
            {
                ptStart = new Point(variable.lpoint[variable.lcaykhungnn[i, 1]].X, variable.lpoint[variable.lcaykhungnn[i, 1]].Y);
                ptEnd = new Point(variable.lpoint[variable.lcaykhungnn[i, 2]].X, variable.lpoint[variable.lcaykhungnn[i, 2]].Y);
                this.DrawLine(g, p, ptStart, ptEnd);
            }
            g.Dispose();
            p.Dispose();

            return variable.bmggraphics;
        }
        public Bitmap DrawDijkstra(Variable variable)
        {
            Graphics g = Graphics.FromImage(variable.bmggraphics);
            Pen p = new Pen(Color.Red, 2);
            Point ptStart, ptEnd;
            string stemp = variable.sdijkstra;
            string[] world = stemp.Split(' ');
            for (int i = 0; i < world.Length - 2; i++)
            {
                ptStart = new Point(variable.lpoint[Convert.ToInt32(world[i]) - 1].X, variable.lpoint[Convert.ToInt32(world[i]) - 1].Y);
                ptEnd = new Point(variable.lpoint[Convert.ToInt32(world[i + 1]) - 1].X, variable.lpoint[Convert.ToInt32(world[i + 1]) - 1].Y);
                this.DrawLine(g, p, ptStart, ptEnd);
            }
            p.Dispose();
            g.Dispose();

            return variable.bmggraphics;
        }
        public Bitmap CreateGraphics(Variable variable, List<Point> lstPointVertex)
        {
            Graphics g = Graphics.FromImage(variable.bmggraphics);
            g.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias;
            g.Clear(Color.White);
            Pen pLine = new Pen(Color.FromArgb(100, 149, 237), 3);
            Brush cbrush = new SolidBrush(Color.Wheat);
            Pen pCircle = new Pen(Color.Black, 2);
            Point ptStart, ptEnd;
            for (int i = 0; i < variable.numbervertex; i++)
            {
                ptStart = new Point(lstPointVertex[i].X, lstPointVertex[i].Y);
                for (int j = 0; j < variable.numbervertex; j++)
                {
                    if (variable.matrixadjacent[i][j] != 0)
                    {
                        ptEnd = new Point(lstPointVertex[j].X, lstPointVertex[j].Y);
                        this.DrawLine(g, pLine, ptStart, ptEnd);
                        Font stringFont = new Font("Arial", 9);
                        SizeF stringSize = g.MeasureString(variable.matrixadjacent[i][j].ToString(), stringFont);
                        g.DrawString(variable.matrixadjacent[i][j].ToString(), stringFont, Brushes.Black, ((ptStart.X + ptEnd.X) / 2), ((ptStart.Y + ptEnd.Y) / 2));
                    }
                }
                /*foreach (int col in row)
                {
                    ptEnd = new Point(lstPointVertex[col].X,lstPointVertex[col].Y);
                    this.DrawLine(g, pLine, ptStart, ptEnd);
                }*/
                int tempy = 5;
                int tempy2 = 5;
                for (int z = 0; z < variable.numbervertex; z++)
                {
                    Font stringFont = new Font("Arial", 9);
                    g.DrawString("    X         Y", stringFont, Brushes.Red, 20, 5);
                    g.DrawString((z + 1).ToString(), stringFont, Brushes.Blue, 5, tempy += 15);
                    string stemp = variable.lpoint[z].X.ToString() + "    " + variable.lpoint[z].Y.ToString();
                    g.DrawString(stemp, stringFont, Brushes.Black, 28, tempy2 += 15);
                }
            }
            for (int temp = 0; temp < variable.numbervertex; temp++)
            {
                Point pt = new Point(lstPointVertex[temp].X - 10, lstPointVertex[temp].Y - 10);
                Rectangle rect = new Rectangle(pt, new Size(20, 20));
                this.DrawVertex(g, cbrush, pCircle, rect, pt, (temp + 1).ToString());
            }
            g.Dispose();
            pLine.Dispose();
            cbrush.Dispose();
            pCircle.Dispose();
            return variable.bmggraphics;
        }

        public void Dijkstra(int start, int end)
        {
            int start1 = start;
            int[] father = new int[variable.numbervertex * 2];
            int[] weight = new int[variable.numbervertex * 2];
            int[] check = new int[variable.numbervertex * 2];

            for (int i = 0; i < variable.numbervertex; i++)
            {
                father[i] = -1;
                weight[i] = 999;
                check[i] = 0;
            }
            father[start] = 0;
            weight[start] = 0;
            int temp;
            do
            {
                temp = -1;
                int min = 999;
                for (int j = 0; j < variable.numbervertex; j++)
                    if (check[j] == 0)
                    {
                        if (variable.matrixadjacent[start][j] != 0 && weight[j] > weight[start] + variable.matrixadjacent[start][j])
                        {
                            weight[j] = weight[start] + variable.matrixadjacent[start][j];
                            father[j] = start;
                        }
                        if (min > weight[j])
                        {
                            min = weight[j];
                            temp = j;
                        }
                    }
                start = temp;
                check[start] = 1;
            } while (temp != -1 && start != end);
            variable.sdijkstra = "";
            getpath(start1, end, father);
        }
        public void getpath(int start, int end, int[] father)
        {
            if (start == end)
            {
                variable.sdijkstra += end + 1 + " ";
            }
            else
            {
                getpath(start, father[end], father);
                variable.sdijkstra += end + 1 + " ";
            }
        }

        public void caykhungnn(Variable variable)
        {
            //int temp = 0;
            int[,] temp=new int[10,3];
            bool[] check = new bool[variable.numbervertex];
            for (int i = 0; i < variable.numbervertex; i++)
            {
                check[i] = true;
                //for (int j = i; j < variable.numbervertex; j++)
                    //temp++;
            }
            int k=0, top, min=0 , l=0 , t=0 , u, w=0;
            int[] s = new int[variable.numbervertex*2];
            variable.socanh = 0; u = variable.chon;
            top = 0;
            s[top] = u;
            check[u] = false;
            while (variable.socanh < variable.numbervertex - 1)
            {
                min = 999;
                for (int i = 0; i <= top; i++)
                {
                    t = s[i];
                    for (int j = 0; j < variable.numbervertex; j++)
                    {
                        if (check[j]==true && min > variable.matrixadjacent[t][j]&& variable.matrixadjacent[t][j]!=0)
                        {
                            min = variable.matrixadjacent[t][j];
                            k = t;
                            l = j;
                        }
                    }
                }
                w = w + min;
                variable.socanh++;
                temp[0, 0] = w;
                temp[variable.socanh, 1] = k;
                temp[variable.socanh, 2] = l;
                check[l] = false;
                top++;
                s[top] = l;
            }
            variable.lcaykhungnn = temp;
        }
        public List<int> DFS(int i)
        {
            Stack s = new Stack();
            List<int> tempdfs = new List<int>();
            int[] visitbfs = new int[variable.numbervertex];
            visitbfs[i] = 1;
            tempdfs.Add(i);
            s.Push(i);
            while (s.Count>0)
            {
                int count = 0;
                i = (int)s.Peek();
                for (int j = 0; j < visitbfs.Length; j++)
                {
                    if (variable.matrixadjacent[i][j] > 0 && visitbfs[j] != 1)
                    {
                        tempdfs.Add(j);
                        visitbfs[j] = 1;
                        s.Push(j);
                        break;
                    }
                    else             
                        count++;
                }
                if (count == visitbfs.Length)
                    s.Pop();
            }
            variable.dfs = tempdfs;
            return variable.dfs;
        }
        public List<int> BFS(int i)
        {
            List<int> tempbfs = new List<int>();
            Queue q = new Queue();
            q.Enqueue(i);
            int[] visitbfs = new int[variable.numbervertex];
            visitbfs[i] = 1;
            while (q.Count!=0)
            {
                int u = (int)q.Dequeue();
                tempbfs.Add(u);
                for (int j = 0; j < variable.numbervertex; j++)
                    if (visitbfs[j]!=1 && variable.matrixadjacent[u][j] > 0)
                    {
                        visitbfs[j] = 1;
                        q.Enqueue(j);
                    }
            }
            variable.bfs = tempbfs;
            return variable.bfs;
        }
    }
}
