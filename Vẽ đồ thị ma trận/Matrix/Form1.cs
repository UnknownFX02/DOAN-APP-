using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace D16TH05
{
    public partial class Form1 : Form
    {
        //List<List<int>> Adjacent;
        //int Vertices;

        Function function = new Function();

        //GraphicsTools g= new GraphicsTools(100,100);
        string FileName;
        public const int PicturePadding = 50;

        public Form1()
        {
            InitializeComponent();
        }

        private void btn_filein_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "Text Document File(*.txt)|*.txt|All File(*.*)|*.*";
            if (ofd.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    this.nup_caykhung.Refresh();
                    this.nup_bfs.Refresh();
                    this.nup_dfs.Refresh();
                    this.cbo_to.Refresh();
                    this.cbo_from.Refresh();
                    this.lv_matran.Items.Clear();
                    this.lv_matran.Columns.Clear();
                    this.lv_danhsach.Items.Clear();
                    this.lv_danhsach.Columns.Clear();
                    this.FileName = ofd.FileName;
                    if (rb_MTK.Checked)
                    {
                        function.variable.matrixadjacent = function.LoadFileMatrix(FileName, lv_matran);
                        function.variable.listadjacent = function.MatrixToList(function.variable, lv_danhsach);
                    }
                    else if (rb_DSK.Checked)
                    {
                        function.variable.listadjacent = function.LoadFileList(FileName, lv_danhsach);
                        function.variable.matrixadjacent = function.ListToMatrix(function.variable, lv_matran);
                    }
                    for(int i=0;i<function.variable.numbervertex;i++)
                    {
                        cbo_from.Items.Add((i + 1).ToString());
                        cbo_to.Items.Add((i + 1).ToString());
                    }
                    nup_caykhung.Maximum = function.variable.numbervertex;
                    nup_dfs.Maximum = function.variable.numbervertex;
                    nup_bfs.Maximum = function.variable.numbervertex;
                }
                catch (Exception EX)
                {
                    MessageBox.Show(EX.Message, "Error");
                }
            }
            ofd.Dispose();
        }

        public void CreateVertex (Variable variable)
        {
            Random number = new Random();
            List<Button> lbutton = new List<Button>();
            for(int i=0;i<variable.numbervertex;i++)
            {
                Button btemp = new Button() { Width=50,Height=50,Location =new Point(number.Next(0,400),number.Next(0,350))};
                btemp.Text = (i+1).ToString();
                btemp.MouseDown += new MouseEventHandler(Button_MouseDown);
                btemp.MouseMove += new MouseEventHandler(Button_MouseMove);
                btemp.BackColor = Color.Blue;
                lbutton.Add(btemp);
                pg_dothi.Controls.Add(btemp);
            }
        }

        private void btn_ve_Click(object sender, EventArgs e)
        {
            //CreateVertex(function.variable);
            //pg_dothi.Paint += new System.Windows.Forms.PaintEventHandler(pictureBox1_Paint);
            function.variable.bmggraphics = function.GraphicsTools();
            function.variable.lpoint = function.RandomVertex(function.variable);
            pg_dothi.Image = this.function.CreateGraphics(function.variable, function.variable.lpoint);
        }


        private Point firstPoint = new Point(0, 0);
        private void Button_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == System.Windows.Forms.MouseButtons.Left)
                firstPoint = new Point(MousePosition.X, MousePosition.Y);
        }
        private void Button_MouseMove(object sender, MouseEventArgs e)
        {
            Control ctr = sender as Control;
            if (e.Button == System.Windows.Forms.MouseButtons.Left)
            {
                Point secondPoint = new Point(MousePosition.X, MousePosition.Y);
                Point temp = new Point(firstPoint.X - secondPoint.X, firstPoint.Y - secondPoint.Y);
                firstPoint = secondPoint;
                ctr.Location = new Point(ctr.Location.X - temp.X, ctr.Location.Y - temp.Y);

            }
        }

        private void btn_save_Click(object sender, EventArgs e)
        {
            function.variable.numbervertex = Convert.ToInt32(txt_edit.Lines[0]);
            for (int i=0;i<function.variable.numbervertex;i++)
            {
                int temp = 0;
                for (int j = 0; j < function.variable.numbervertex; j++)
                {
                    function.variable.matrixadjacent[i][j] = Convert.ToInt32(txt_edit.Lines[i+1][temp]-48);
                    temp = temp + 2;
                }
            }
            this.lv_matran.Items.Clear();
            this.lv_matran.Columns.Clear();
            this.lv_danhsach.Items.Clear();
            this.lv_danhsach.Columns.Clear();
            function.variable.listadjacent = function.MatrixToList(function.variable, lv_danhsach);
            function.variable.matrixadjacent = function.ListToMatrix(function.variable, lv_matran);
        }

        private void btn_clear_Click(object sender, EventArgs e)
        {
            if (chb_write.Checked)
            {
                txt_edit.ReadOnly = false;
            }
            else
            {
                txt_edit.Clear();
                txt_edit.AppendText(function.variable.numbervertex + "\n");
                for (int i = 0; i < function.variable.numbervertex; i++)
                {
                    for (int j = 0; j < function.variable.numbervertex; j++)
                    {
                        txt_edit.AppendText(function.variable.matrixadjacent[i][j] + " ");
                    }
                    txt_edit.AppendText("\n");
                }
                txt_edit.ReadOnly = true;
            }
        }

        private void btn_Dijkstra_Click(object sender, EventArgs e)
        {
            this.txt_dijkstra.Text = "";
            txt_dijkstra.ReadOnly = true;
            int start = this.cbo_to.SelectedIndex;
            int end = this.cbo_from.SelectedIndex;
            function.Dijkstra(start, end);
            txt_dijkstra.Text = function.variable.sdijkstra;
            pg_dothi.Image = this.function.DrawDijkstra(function.variable);
        }
        private void btn_caykhungnn_Click(object sender, EventArgs e)
        {
            txt_caykhung.Clear();
            txt_caykhung.ReadOnly = true;
            function.caykhungnn(function.variable);
            function.variable.chon = Convert.ToInt32(Math.Round(nup_caykhung.Value, 0));
            txt_caykhung.Text = function.variable.lcaykhungnn[0, 0] + "\n";
            for (int i = 1; i <= function.variable.socanh; i++)
                txt_caykhung.Text += (function.variable.lcaykhungnn[i,1]+1) + " " + (function.variable.lcaykhungnn[i,2]+1) + "\n";
            pg_dothi.Image = this.function.Drawcaykhung(function.variable);
        }
        private void btn_DFS_Click(object sender, EventArgs e)
        {
            txt_dfs.Clear();
            function.DFS(Convert.ToInt32(Math.Round(nup_dfs.Value, 0))-1);
            for (int i = 0; i < function.variable.numbervertex; i++)
                txt_dfs.Text += function.variable.dfs[i] + 1 + "\n";
        }
        private void btn_BFS_Click(object sender, EventArgs e)
        {
            txt_bfs.Clear();
            function.BFS(Convert.ToInt32(nup_bfs.Value)-1);
            for (int i = 0; i < function.variable.numbervertex; i++)
                txt_bfs.Text += function.variable.bfs[i]+1 + "\n";
        }
















    }
}
