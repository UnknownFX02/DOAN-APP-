namespace D16TH05
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.pg_dothi = new System.Windows.Forms.PictureBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.lv_matran = new System.Windows.Forms.ListView();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.rb_DSK = new System.Windows.Forms.RadioButton();
            this.rb_MTK = new System.Windows.Forms.RadioButton();
            this.btn_filein = new System.Windows.Forms.Button();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.btn_clear = new System.Windows.Forms.Button();
            this.btn_save = new System.Windows.Forms.Button();
            this.chb_write = new System.Windows.Forms.CheckBox();
            this.txt_edit = new System.Windows.Forms.TextBox();
            this.groupBox7 = new System.Windows.Forms.GroupBox();
            this.btn_dijkstra = new System.Windows.Forms.Button();
            this.cbo_to = new System.Windows.Forms.ComboBox();
            this.cbo_from = new System.Windows.Forms.ComboBox();
            this.txt_dijkstra = new System.Windows.Forms.TextBox();
            this.btn_ve = new System.Windows.Forms.Button();
            this.btn_caykhung = new System.Windows.Forms.Button();
            this.txt_caykhung = new System.Windows.Forms.TextBox();
            this.nup_caykhung = new System.Windows.Forms.NumericUpDown();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.lv_danhsach = new System.Windows.Forms.ListView();
            this.groupbox8 = new System.Windows.Forms.GroupBox();
            this.txt_dfs = new System.Windows.Forms.TextBox();
            this.btn_dfs = new System.Windows.Forms.Button();
            this.nup_dfs = new System.Windows.Forms.NumericUpDown();
            this.groupbox9 = new System.Windows.Forms.GroupBox();
            this.txt_bfs = new System.Windows.Forms.TextBox();
            this.btn_bfs = new System.Windows.Forms.Button();
            this.nup_bfs = new System.Windows.Forms.NumericUpDown();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pg_dothi)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox6.SuspendLayout();
            this.groupBox7.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nup_caykhung)).BeginInit();
            this.groupBox4.SuspendLayout();
            this.groupbox8.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nup_dfs)).BeginInit();
            this.groupbox9.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nup_bfs)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.pg_dothi);
            this.groupBox3.Location = new System.Drawing.Point(353, 34);
            this.groupBox3.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox3.Size = new System.Drawing.Size(562, 586);
            this.groupBox3.TabIndex = 5;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Đồ Thị";
            // 
            // pg_dothi
            // 
            this.pg_dothi.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.pg_dothi.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.pg_dothi.Location = new System.Drawing.Point(21, 23);
            this.pg_dothi.Margin = new System.Windows.Forms.Padding(4);
            this.pg_dothi.Name = "pg_dothi";
            this.pg_dothi.Size = new System.Drawing.Size(525, 545);
            this.pg_dothi.TabIndex = 0;
            this.pg_dothi.TabStop = false;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.lv_matran);
            this.groupBox1.Location = new System.Drawing.Point(923, 43);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox1.Size = new System.Drawing.Size(246, 289);
            this.groupBox1.TabIndex = 6;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Ma Trận Kề";
            // 
            // lv_matran
            // 
            this.lv_matran.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.lv_matran.GridLines = true;
            this.lv_matran.Location = new System.Drawing.Point(8, 23);
            this.lv_matran.Margin = new System.Windows.Forms.Padding(4);
            this.lv_matran.Name = "lv_matran";
            this.lv_matran.Size = new System.Drawing.Size(228, 258);
            this.lv_matran.TabIndex = 0;
            this.lv_matran.UseCompatibleStateImageBehavior = false;
            this.lv_matran.View = System.Windows.Forms.View.Details;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.groupBox5);
            this.groupBox2.Controls.Add(this.groupBox6);
            this.groupBox2.Controls.Add(this.groupBox7);
            this.groupBox2.Controls.Add(this.btn_ve);
            this.groupBox2.Controls.Add(this.btn_caykhung);
            this.groupBox2.Controls.Add(this.txt_caykhung);
            this.groupBox2.Controls.Add(this.nup_caykhung);
            this.groupBox2.Location = new System.Drawing.Point(13, 43);
            this.groupBox2.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox2.Size = new System.Drawing.Size(329, 577);
            this.groupBox2.TabIndex = 7;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Chức Năng";
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.rb_DSK);
            this.groupBox5.Controls.Add(this.rb_MTK);
            this.groupBox5.Controls.Add(this.btn_filein);
            this.groupBox5.Location = new System.Drawing.Point(15, 40);
            this.groupBox5.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox5.Size = new System.Drawing.Size(306, 86);
            this.groupBox5.TabIndex = 2;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Nhập";
            // 
            // rb_DSK
            // 
            this.rb_DSK.AutoSize = true;
            this.rb_DSK.Location = new System.Drawing.Point(8, 52);
            this.rb_DSK.Margin = new System.Windows.Forms.Padding(4);
            this.rb_DSK.Name = "rb_DSK";
            this.rb_DSK.Size = new System.Drawing.Size(120, 21);
            this.rb_DSK.TabIndex = 3;
            this.rb_DSK.TabStop = true;
            this.rb_DSK.Text = "Danh Sách Kề";
            this.rb_DSK.UseVisualStyleBackColor = true;
            // 
            // rb_MTK
            // 
            this.rb_MTK.AutoSize = true;
            this.rb_MTK.Location = new System.Drawing.Point(8, 23);
            this.rb_MTK.Margin = new System.Windows.Forms.Padding(4);
            this.rb_MTK.Name = "rb_MTK";
            this.rb_MTK.Size = new System.Drawing.Size(103, 21);
            this.rb_MTK.TabIndex = 0;
            this.rb_MTK.TabStop = true;
            this.rb_MTK.Text = "Ma Trận Kề";
            this.rb_MTK.UseVisualStyleBackColor = true;
            // 
            // btn_filein
            // 
            this.btn_filein.Location = new System.Drawing.Point(144, 23);
            this.btn_filein.Margin = new System.Windows.Forms.Padding(4);
            this.btn_filein.Name = "btn_filein";
            this.btn_filein.Size = new System.Drawing.Size(100, 49);
            this.btn_filein.TabIndex = 0;
            this.btn_filein.Text = "File";
            this.btn_filein.UseVisualStyleBackColor = true;
            this.btn_filein.Click += new System.EventHandler(this.btn_filein_Click);
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.btn_clear);
            this.groupBox6.Controls.Add(this.btn_save);
            this.groupBox6.Controls.Add(this.chb_write);
            this.groupBox6.Controls.Add(this.txt_edit);
            this.groupBox6.Location = new System.Drawing.Point(15, 134);
            this.groupBox6.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox6.Size = new System.Drawing.Size(296, 178);
            this.groupBox6.TabIndex = 2;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "Sữa";
            // 
            // btn_clear
            // 
            this.btn_clear.Location = new System.Drawing.Point(167, 86);
            this.btn_clear.Margin = new System.Windows.Forms.Padding(4);
            this.btn_clear.Name = "btn_clear";
            this.btn_clear.Size = new System.Drawing.Size(120, 49);
            this.btn_clear.TabIndex = 0;
            this.btn_clear.Text = "Defaults";
            this.btn_clear.UseVisualStyleBackColor = true;
            this.btn_clear.Click += new System.EventHandler(this.btn_clear_Click);
            // 
            // btn_save
            // 
            this.btn_save.Location = new System.Drawing.Point(167, 25);
            this.btn_save.Margin = new System.Windows.Forms.Padding(4);
            this.btn_save.Name = "btn_save";
            this.btn_save.Size = new System.Drawing.Size(120, 49);
            this.btn_save.TabIndex = 0;
            this.btn_save.Text = "Save";
            this.btn_save.UseVisualStyleBackColor = true;
            this.btn_save.Click += new System.EventHandler(this.btn_save_Click);
            // 
            // chb_write
            // 
            this.chb_write.Location = new System.Drawing.Point(173, 148);
            this.chb_write.Margin = new System.Windows.Forms.Padding(4);
            this.chb_write.Name = "chb_write";
            this.chb_write.Size = new System.Drawing.Size(120, 25);
            this.chb_write.TabIndex = 1;
            this.chb_write.Text = "Read/Write";
            // 
            // txt_edit
            // 
            this.txt_edit.Location = new System.Drawing.Point(8, 25);
            this.txt_edit.Margin = new System.Windows.Forms.Padding(4);
            this.txt_edit.Multiline = true;
            this.txt_edit.Name = "txt_edit";
            this.txt_edit.Size = new System.Drawing.Size(157, 124);
            this.txt_edit.TabIndex = 0;
            // 
            // groupBox7
            // 
            this.groupBox7.Controls.Add(this.btn_dijkstra);
            this.groupBox7.Controls.Add(this.cbo_to);
            this.groupBox7.Controls.Add(this.cbo_from);
            this.groupBox7.Controls.Add(this.txt_dijkstra);
            this.groupBox7.Location = new System.Drawing.Point(8, 315);
            this.groupBox7.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox7.Name = "groupBox7";
            this.groupBox7.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox7.Size = new System.Drawing.Size(306, 127);
            this.groupBox7.TabIndex = 3;
            this.groupBox7.TabStop = false;
            this.groupBox7.Text = "Dijkstra";
            // 
            // btn_dijkstra
            // 
            this.btn_dijkstra.Location = new System.Drawing.Point(14, 80);
            this.btn_dijkstra.Margin = new System.Windows.Forms.Padding(4);
            this.btn_dijkstra.Name = "btn_dijkstra";
            this.btn_dijkstra.Size = new System.Drawing.Size(279, 31);
            this.btn_dijkstra.TabIndex = 1;
            this.btn_dijkstra.Text = "Dijkstra";
            this.btn_dijkstra.Click += new System.EventHandler(this.btn_Dijkstra_Click);
            // 
            // cbo_to
            // 
            this.cbo_to.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbo_to.FormattingEnabled = true;
            this.cbo_to.Location = new System.Drawing.Point(14, 48);
            this.cbo_to.Margin = new System.Windows.Forms.Padding(4);
            this.cbo_to.Name = "cbo_to";
            this.cbo_to.Size = new System.Drawing.Size(132, 24);
            this.cbo_to.TabIndex = 4;
            // 
            // cbo_from
            // 
            this.cbo_from.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbo_from.FormattingEnabled = true;
            this.cbo_from.Location = new System.Drawing.Point(161, 48);
            this.cbo_from.Margin = new System.Windows.Forms.Padding(4);
            this.cbo_from.Name = "cbo_from";
            this.cbo_from.Size = new System.Drawing.Size(132, 24);
            this.cbo_from.TabIndex = 2;
            // 
            // txt_dijkstra
            // 
            this.txt_dijkstra.Location = new System.Drawing.Point(14, 19);
            this.txt_dijkstra.Margin = new System.Windows.Forms.Padding(4);
            this.txt_dijkstra.Name = "txt_dijkstra";
            this.txt_dijkstra.Size = new System.Drawing.Size(279, 22);
            this.txt_dijkstra.TabIndex = 0;
            // 
            // btn_ve
            // 
            this.btn_ve.Location = new System.Drawing.Point(180, 500);
            this.btn_ve.Margin = new System.Windows.Forms.Padding(4);
            this.btn_ve.Name = "btn_ve";
            this.btn_ve.Size = new System.Drawing.Size(117, 49);
            this.btn_ve.TabIndex = 1;
            this.btn_ve.Text = "Vẽ";
            this.btn_ve.UseVisualStyleBackColor = true;
            this.btn_ve.Click += new System.EventHandler(this.btn_ve_Click);
            // 
            // btn_caykhung
            // 
            this.btn_caykhung.Location = new System.Drawing.Point(144, 406);
            this.btn_caykhung.Margin = new System.Windows.Forms.Padding(4);
            this.btn_caykhung.Name = "btn_caykhung";
            this.btn_caykhung.Size = new System.Drawing.Size(117, 25);
            this.btn_caykhung.TabIndex = 4;
            this.btn_caykhung.Text = "Min Spanning Tree";
            this.btn_caykhung.Click += new System.EventHandler(this.btn_caykhungnn_Click);
            // 
            // txt_caykhung
            // 
            this.txt_caykhung.Location = new System.Drawing.Point(15, 450);
            this.txt_caykhung.Margin = new System.Windows.Forms.Padding(4);
            this.txt_caykhung.Multiline = true;
            this.txt_caykhung.Name = "txt_caykhung";
            this.txt_caykhung.Size = new System.Drawing.Size(152, 99);
            this.txt_caykhung.TabIndex = 5;
            // 
            // nup_caykhung
            // 
            this.nup_caykhung.Location = new System.Drawing.Point(218, 455);
            this.nup_caykhung.Margin = new System.Windows.Forms.Padding(4);
            this.nup_caykhung.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.nup_caykhung.Name = "nup_caykhung";
            this.nup_caykhung.Size = new System.Drawing.Size(67, 22);
            this.nup_caykhung.TabIndex = 6;
            this.nup_caykhung.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.lv_danhsach);
            this.groupBox4.Location = new System.Drawing.Point(923, 340);
            this.groupBox4.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox4.Size = new System.Drawing.Size(246, 280);
            this.groupBox4.TabIndex = 8;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Danh Sách Kề";
            // 
            // lv_danhsach
            // 
            this.lv_danhsach.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.lv_danhsach.GridLines = true;
            this.lv_danhsach.Location = new System.Drawing.Point(8, 23);
            this.lv_danhsach.Margin = new System.Windows.Forms.Padding(4);
            this.lv_danhsach.Name = "lv_danhsach";
            this.lv_danhsach.Size = new System.Drawing.Size(228, 239);
            this.lv_danhsach.TabIndex = 0;
            this.lv_danhsach.UseCompatibleStateImageBehavior = false;
            this.lv_danhsach.View = System.Windows.Forms.View.Details;
            // 
            // groupbox8
            // 
            this.groupbox8.Controls.Add(this.txt_dfs);
            this.groupbox8.Controls.Add(this.btn_dfs);
            this.groupbox8.Controls.Add(this.nup_dfs);
            this.groupbox8.Location = new System.Drawing.Point(1188, 43);
            this.groupbox8.Margin = new System.Windows.Forms.Padding(4);
            this.groupbox8.Name = "groupbox8";
            this.groupbox8.Padding = new System.Windows.Forms.Padding(4);
            this.groupbox8.Size = new System.Drawing.Size(214, 289);
            this.groupbox8.TabIndex = 9;
            this.groupbox8.TabStop = false;
            this.groupbox8.Text = "DFS";
            // 
            // txt_dfs
            // 
            this.txt_dfs.Location = new System.Drawing.Point(17, 23);
            this.txt_dfs.Margin = new System.Windows.Forms.Padding(4);
            this.txt_dfs.Multiline = true;
            this.txt_dfs.Name = "txt_dfs";
            this.txt_dfs.Size = new System.Drawing.Size(172, 211);
            this.txt_dfs.TabIndex = 0;
            // 
            // btn_dfs
            // 
            this.btn_dfs.Location = new System.Drawing.Point(8, 246);
            this.btn_dfs.Margin = new System.Windows.Forms.Padding(4);
            this.btn_dfs.Name = "btn_dfs";
            this.btn_dfs.Size = new System.Drawing.Size(100, 28);
            this.btn_dfs.TabIndex = 1;
            this.btn_dfs.Text = "DFS";
            this.btn_dfs.Click += new System.EventHandler(this.btn_DFS_Click);
            // 
            // nup_dfs
            // 
            this.nup_dfs.Location = new System.Drawing.Point(122, 250);
            this.nup_dfs.Margin = new System.Windows.Forms.Padding(4);
            this.nup_dfs.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.nup_dfs.Name = "nup_dfs";
            this.nup_dfs.Size = new System.Drawing.Size(67, 22);
            this.nup_dfs.TabIndex = 2;
            this.nup_dfs.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // groupbox9
            // 
            this.groupbox9.Controls.Add(this.txt_bfs);
            this.groupbox9.Controls.Add(this.btn_bfs);
            this.groupbox9.Controls.Add(this.nup_bfs);
            this.groupbox9.Location = new System.Drawing.Point(1188, 340);
            this.groupbox9.Margin = new System.Windows.Forms.Padding(4);
            this.groupbox9.Name = "groupbox9";
            this.groupbox9.Padding = new System.Windows.Forms.Padding(4);
            this.groupbox9.Size = new System.Drawing.Size(214, 280);
            this.groupbox9.TabIndex = 10;
            this.groupbox9.TabStop = false;
            this.groupbox9.Text = "BFS";
            // 
            // txt_bfs
            // 
            this.txt_bfs.Location = new System.Drawing.Point(17, 23);
            this.txt_bfs.Margin = new System.Windows.Forms.Padding(4);
            this.txt_bfs.Multiline = true;
            this.txt_bfs.Name = "txt_bfs";
            this.txt_bfs.Size = new System.Drawing.Size(164, 211);
            this.txt_bfs.TabIndex = 0;
            // 
            // btn_bfs
            // 
            this.btn_bfs.Location = new System.Drawing.Point(8, 242);
            this.btn_bfs.Margin = new System.Windows.Forms.Padding(4);
            this.btn_bfs.Name = "btn_bfs";
            this.btn_bfs.Size = new System.Drawing.Size(100, 28);
            this.btn_bfs.TabIndex = 1;
            this.btn_bfs.Text = "BFS";
            this.btn_bfs.Click += new System.EventHandler(this.btn_BFS_Click);
            // 
            // nup_bfs
            // 
            this.nup_bfs.Location = new System.Drawing.Point(124, 244);
            this.nup_bfs.Margin = new System.Windows.Forms.Padding(4);
            this.nup_bfs.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.nup_bfs.Name = "nup_bfs";
            this.nup_bfs.Size = new System.Drawing.Size(67, 22);
            this.nup_bfs.TabIndex = 2;
            this.nup_bfs.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1421, 635);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupbox8);
            this.Controls.Add(this.groupbox9);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBox3.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pg_dothi)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            this.groupBox6.ResumeLayout(false);
            this.groupBox6.PerformLayout();
            this.groupBox7.ResumeLayout(false);
            this.groupBox7.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nup_caykhung)).EndInit();
            this.groupBox4.ResumeLayout(false);
            this.groupbox8.ResumeLayout(false);
            this.groupbox8.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nup_dfs)).EndInit();
            this.groupbox9.ResumeLayout(false);
            this.groupbox9.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nup_bfs)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.PictureBox pg_dothi;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button btn_filein;
        private System.Windows.Forms.Button btn_ve;
        private System.Windows.Forms.ListView lv_matran;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.ListView lv_danhsach;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.RadioButton rb_DSK;
        private System.Windows.Forms.RadioButton rb_MTK;
        private System.Windows.Forms.TextBox txt_edit;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.Button btn_clear;
        private System.Windows.Forms.Button btn_save;
        private System.Windows.Forms.CheckBox chb_write;
        private System.Windows.Forms.TextBox txt_dijkstra;
        private System.Windows.Forms.GroupBox groupBox7;
        private System.Windows.Forms.ComboBox cbo_to;
        private System.Windows.Forms.ComboBox cbo_from;
        private System.Windows.Forms.Button btn_dijkstra;
        private System.Windows.Forms.Button btn_caykhung;
        private System.Windows.Forms.TextBox txt_caykhung;
        private System.Windows.Forms.NumericUpDown nup_caykhung;
        private System.Windows.Forms.GroupBox groupbox8;
        private System.Windows.Forms.GroupBox groupbox9;
        private System.Windows.Forms.TextBox txt_dfs;
        private System.Windows.Forms.TextBox txt_bfs;
        private System.Windows.Forms.Button btn_dfs;
        private System.Windows.Forms.Button btn_bfs;
        private System.Windows.Forms.NumericUpDown nup_dfs;
        private System.Windows.Forms.NumericUpDown nup_bfs;
    }
}

