(function() {
    function p(a) {
        f && (b = b + (a.pageX - a.target.offsetLeft) + " " + (a.pageY - a.target.offsetTop) + " " + (new Date).getTime() / 1E3 + "\n", g.value = b);
        return !1
    }
    function h() {
        for (var a = [0, 1, 2, 3, 4, 5], b = 1; 6 > b; b++) {
            e *= 53;
            e %= 1000000009;
            var k = e % (b + 1),
                d = a[b];
            a[b] = a[k];
            a[k] = d
        }
        return a
    }
    function l() {
        m.innerHTML = '<canvas id="canimg" width="600" height="400"></canvas>';
        var a = m.firstChild;
        a.onclick = p;
        a.a = function() {
            return !1
        };
        a = a.getContext("2d");
        a.fillStyle = "rgb(200, 200, 200)";
        a.fillRect(0, 0, 600, 400);
        for (var b = [
            [50, 50],
            [50, 150],
            [50, 250],
            [150, 50],
            [150, 150],
            [150, 250]
        ], d = [
            [250, 50],
            [250, 150],
            [250, 250],
            [450, 50],
            [450, 150],
            [450, 250]
        ], e = "#ff0000 #00ff00 #0000ff #ffff00 #ff8800 #ff00ff".split(" "), f = h(), g = h(), c = 0; 6 > c; c++) a.fillStyle = e[f[c]], a.fillRect(b[c][0], b[c][1], 50, 50);
        for (c = 0; 6 > c; c++) a.fillStyle = e[g[c]], a.fillRect(d[c][0], d[c][1], 100, 50)
    }
    var b = "",
        d = 0,
        f = !0,
        e = 47,
        m = document.getElementById("imagecont"),
        n = document.getElementById("command");
    next = function() {
        alert(f);
        if (f) {
            var a = (new Date).getTime() / 1E3;
            d == commands.length ? (b = b + "done " + a + "\n", n.innerHTML = "Congratulations. Submit your action log.", f = !1) : (b = b + "next " + a + "\n", n.innerHTML = "<b>Level " + (d + 2) + ":</b> " + commands[d] + " Then click on the <b>Next</b> button.", d += 1, l());
            g.value = b
        }
    };
    var g = document.getElementById("log");
    l();
    e = 47
})();
